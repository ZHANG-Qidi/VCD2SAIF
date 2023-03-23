;;; Version 1.0
;;; Date 2022年  1月 27日 木曜日 04:36:13 JST
;;; =====================================包定义区=====================================
;;; 定义包：PACKAGE_VCD2SAIF
;;; 使用包：COMMON-LISP
;;; 定义昵称：NICKNAME_VCD2SAIF
;;; 导出符号：VCD2SAIF
(defpackage "PACKAGE_VCD2SAIF"
  (:use "COMMON-LISP")
  (:nicknames "NICKNAME_VCD2SAIF")
  (:export "VCD2SAIF"))
;;; 确保当前包是：PACKAGE_VCD2SAIF
(in-package PACKAGE_VCD2SAIF)
;;; =====================================包定义区结束=====================================
;;; =====================================宏定义区=====================================
;;; 另一版将元素推至列表尾端的 push 可写成：
;;; push val to the last of list
(define-modify-macro append1f (val)
  (lambda (lst val) (append lst (list val))))
;;; 返回列表最后一个元素
;;; return the last atom of list
(defmacro nth_last (lst)
  `(car (last ,lst)))
;;; =====================================宏定义区结束=====================================
;;; ===================================== 定义结构体 =====================================
(defstruct (saif_struct)
  (SAIFILE 'SAIFILE)
  (SAIFVERSION '(SAIFVERSION "\"2.0\""))
  (DIRECTION '(DIRECTION "\"backward\""))
  (DESIGN '(DESIGN " "))
  (date nil)
  (VENDOR '(VENDOR "\"Xilinx, Inc\""))
  (PROGRAM_NAME '(PROGRAM_NAME "\"Vivado Simulator & VCD2SAIF\""))
  (version nil)
  (DIVIDER '(DIVIDER /))
  (timescale nil)
  (duration nil)
  (instance_output nil))
;;; ===================================== 定义结构体结束 =====================================
;;; =====================================包载入区=====================================
;;; =====================================包载入区结束=====================================
;;; =====================================函数定义区=====================================
;;; =====================================通用函数定义区=====================================
;;; 以非空格可打印字符为基准
;;; 当C为非空格时为真
(defun constituent (c)
  (and (graphic-char-p c)
       (char/= c #\ )))
;;; 以test函数为基础，提取语元
;;; 返回值函数
;;; 递归函数
;;; base on test, get tokens
(defun tokens (str test start)
  ;;; 找到第一个非空格字符
  (let ((p1 (position-if test str :start start)))
    (if p1
        ;;; 找到第一个非空格字符后的第一个空格字符
        ;;; 找到字符串末尾时p2为NIL
        (let ((p2 (position-if #'(lambda (c)
                                   (not (funcall test c)))
                               str :start p1)))
          ;;; 提取第一个非空格字符后的第一个空格字符前的非空格字符串
          (cons (subseq str p1 p2)
                ;;; 当未找到文件末尾时继续以当前空格字符为起始向后查找
                (if p2
                    (tokens str test p2)
                    nil)))
        nil)))
;;; 格式化字符串为SAIF标准
;;; format string to SAIF standard
(defun string_modify (x)
  (let ((x (copy-tree x)))
    (cond ((char= #\\ (aref x 0))
           (setf x (subseq x 1))))
    (do ((i 0 (+ i 1)))
        ((>= i (length x)) x)
      (cond ((member (aref x i) (list #\[ #\] #\< #\> #\/ #\. #\^))
             (setf x (concatenate 'string (subseq x 0 i) "\\" (subseq x i)))
             (incf i))))))
;;; ===================================== 通用函数定义区结束 =====================================
;;; ===================================== SAIF函数开始 ==================================
;;; 向instance中插入INSTANCE
;;; insert module to instance
(defun insert_module_instance (instance instance_level module)
  (let ((instance (copy-tree instance)))
    (cond ((= 0 instance_level)
           (list module))
          ((= 1 instance_level)
           (append1f instance (list module)))
          (t (do ((i 2 (+ i 1))
                  (sub_instance instance (nth_last sub_instance)))
                 ((= i instance_level)
                  (progn
                    (append1f (nth_last sub_instance) (list module))
                    instance)))))))
;;; 生成instance列表
;;; instance_list 以 nil 值传入函数，在运行中根据 value_changes_ht 构建 instance_list
;;; 根据 instance_list 从 node_info_ht 中读取 变量名，标识符，位数相关信息
(defun make_instance_output (instance node_info_ht value_changes_ht instance_list)
  (let ((instance_output nil))
    (cond ((not (null (car instance)))
           (append1f instance_output "INSTANCE")
           (append1f instance_output (car instance))
           ;; 构建instance_list
           (append1f instance_list (car instance))
           (cond ((not (null (gethash instance_list node_info_ht)))
                  (let ((NET (list "NET")))
                    (dolist (obj (gethash instance_list node_info_ht))
                      ;; 从value_changes_ht 和 node_info_ht中抽取信息构建NET
                      (append1f NET (append (list (car obj)) (cadr (gethash (nth 2 obj) (gethash (nth 1 obj) value_changes_ht))))))
                    (append1f instance_output NET))))
           ;; 对剩余的instance列表进行遍历，遍历因为可能存在同级别instance
           (dolist (obj (cdr instance) instance_output)
             (append1f instance_output (make_instance_output obj node_info_ht value_changes_ht instance_list)))))))
;;; ===================================== SAIF函数结束 ==================================
;;; ===================================== 打印函数定义区 =====================================
;;; 输出列表格式化
;;; format list to ASIF standard
(defun simple-pprint-defun (*standard-output* list)
  (let ((*print-escape* nil))
    (pprint-logical-block (*standard-output* list :prefix "(" :suffix ")")
      (dolist (obj list)
        (cond ((equal "INSTANCE" obj)
               (write obj)
               (write-char #\Space))
              ((not (listp obj))
               (write obj))
              ((and (listp obj)
                    (or (and (equal "INSTANCE" (car obj))
                             (not (listp (cadr obj))))
                        (and (equal "NET" (car obj))
                             (= 7 (length (cadr obj))))))
               (pprint-indent :block 2)
               (pprint-newline :mandatory)
               (simple-pprint-defun *standard-output* obj))
              ((listp obj)
               (pprint-indent :block 2)
               (pprint-newline :mandatory)
               (write obj))))
      (pprint-indent :block -1)
      (pprint-newline :mandatory))))
;;; 打印SAIF文件
;;; 无返回值
;;; print file
(defun file_print (file_output saifile)
  (let ((file_saif (list (saif_struct-saifile saifile)
                         (saif_struct-saifversion saifile)
                         (saif_struct-direction saifile)
                         (saif_struct-design saifile)
                         (saif_struct-date saifile)
                         (saif_struct-vendor saifile)
                         (saif_struct-program_name saifile)
                         (saif_struct-version saifile)
                         (saif_struct-divider saifile)
                         (saif_struct-timescale saifile)
                         (saif_struct-duration saifile)
                         (saif_struct-instance_output saifile))))
    ;;; 将file列表内容写入输出文件
    (with-open-file (str file_output :direction :output :if-exists :supersede)
      (simple-pprint-defun str file_saif)
      (write-char #\Newline str))))
;;; ===================================== 打印函数定义区结束 =====================================
;;; ===================================== 主函数开始 =====================================
(defun vcd2saif (vcd_file &key (simulation_time 0) (split_interval 0) (tcl_count 0))
  (let* ((*print-right-margin* 10000)
         (vcd_file_path (make-pathname :name vcd_file))
         (header_info (list '(date . data) '(version . data) '(timescale . data)))
         (instance nil)
         (instance_list nil)
         (instance_level 0)
         (node_info_ht (make-hash-table :test #'equal))
         (value_changes_ht (make-hash-table :test #'equal))
         (value_changes_split_start_ht (make-hash-table :test #'equal))
         (value_changes_split_end_ht (make-hash-table :test #'equal))
         (value_changes_split_range_ht (make-hash-table :test #'equal))
         (simulation_time_new nil)
         (saifile (make-saif_struct))
         (split_time split_interval)
         (saif_folder (concatenate 'string
                                   (subseq vcd_file 0 (position #\. vcd_file :from-end t))
                                   "_vcd2saif_saif/"))
         (power_report_folder (concatenate 'string
                                           (subseq vcd_file 0 (position #\. vcd_file :from-end t))
                                           "_vcd2saif_power_report/"))
         (saif_file_list nil)
         (current_time (GET-INTERNAL-REAL-TIME)))
    ;; 创建saif文件夹
    (ensure-directories-exist saif_folder)
    ;; 创建电力报告文件夹
    (ensure-directories-exist power_report_folder)
    ;; 分组读入
    ;; 每组数据长度 8192
    (let ((buffer_before nil)
          (buffer_after nil))
      (with-open-file (in vcd_file_path)
        (loop with buffer = (make-array 8192 :element-type 'character)
              for n-characters = (read-sequence buffer in)
              while (< 0 n-characters)
              do
                 ;; 对buffer以实际读取到的字符长度n-characters进行截取
                 (setf buffer (subseq buffer 0 n-characters))
                 ;; 从末尾查找第一个换行符号，以该符号分割读取的 8192 个字符，对分割前的字符串进行处理
                 (setf buffer_before (concatenate 'string buffer_after (subseq buffer 0 (position #\Linefeed buffer :from-end t))))
                 ;; 对分割后的字符串即是不满足一行的字符串，进行保留，加到下一个分割之前的字符串，组成完整整行字符串
                 (setf buffer_after (subseq buffer (position #\Linefeed buffer :from-end t)))
                 ;; 对分割前的字符串进行处理，读取为单词列表
                 (let ((lines (tokens buffer_before #'constituent 0)))
                   ;; 遍历当前单词列表
                   (do* ((obj (car lines) (car lines)))
                        ((null obj) 'done)
                     ;; 更新lines
                     (setf lines (cdr lines))
                     ;; 当单词以#开始时，为时间戳信息，读取时间信息
                     (cond ((char= #\# (aref obj 0))
                            ;; 读取时间戳信息到simulation_time_new
                            (setf simulation_time_new (read-from-string (subseq obj 1)))
                            ;; 如果分割间隔设置不为0,则进行分割处理
                            (cond ((and (/= split_interval 0)
                                        ;; 新时间戳大于分割间隔，开始进行分割处理
                                        (>= simulation_time_new split_time))
                                   ;; 遍历value_changes_ht
                                   ;; k为标识符
                                   ;; v为信号信息哈希表
                                   (maphash #'(lambda (k v)
                                                ;; 遍历v，也就是遍历信号信息哈希表
                                                ;; k1为信号位数
                                                ;; v1为信号信息列表
                                                (maphash #'(lambda (k1 v1)
                                                             ;; 从 value_changes_ht 复制信号变化信息到 value_changes_split_end_ht
                                                             (setf (gethash k1 (gethash k value_changes_split_end_ht)) (copy-tree v1))
                                                             ;; 根据 split_time 更新 value_changes_split_end_ht
                                                             (let* ((simulation_time_old (nth 0 (car v1)))
                                                                    (scalar_value_old (nth 1 (car v1))))
                                                               (incf (cadr (nth (cdr (assoc scalar_value_old '((#\0 . 0) (#\1 . 1) (#\x . 2) (#\z . 3))))
                                                                                (cadr (gethash k1 (gethash k value_changes_split_end_ht)))))
                                                                     (- split_time simulation_time_old))
                                                               (setf (caar (gethash k1 (gethash k value_changes_split_end_ht))) split_time))
                                                             ;; 计算 value_changes_split_range_ht
                                                             (let ((v1_value_changes_split_end_ht (gethash k1 (gethash k value_changes_split_end_ht)))
                                                                   (v1_value_changes_split_start_ht (gethash k1 (gethash k value_changes_split_start_ht))))
                                                               ;; 判断是否为第一次处理，如果是则 value_changes_split_start_ht 还未被初始化
                                                               (cond ((= split_time split_interval)
                                                                      ;; value_changes_split_range_ht 赋值为 value_changes_split_end_ht
                                                                      (setf (gethash k1 (gethash k value_changes_split_range_ht)) (copy-tree v1_value_changes_split_end_ht)))
                                                                     (t
                                                                      ;; value_changes_split_range_ht 赋值为 value_changes_split_end_ht 与 value_changes_split_start_ht 的差
                                                                      ;; value_changes_split_range_ht 信号和时间信息赋值为信号变化和时间变化
                                                                      (setf (car (gethash k1 (gethash k value_changes_split_range_ht))) (list (list (caar v1_value_changes_split_start_ht) (caar v1_value_changes_split_end_ht))
                                                                                                                                              (list (cadar v1_value_changes_split_start_ht) (cadar v1_value_changes_split_end_ht))))
                                                                      (do ((i 0 (1+ i)))
                                                                          ((= i 6) 'done)
                                                                        ;; 后续累计信息赋值为差值
                                                                        (setf (cadr (nth i (cadr (gethash k1 (gethash k value_changes_split_range_ht)))))
                                                                              (- (cadr (nth i (cadr v1_value_changes_split_end_ht)))
                                                                                 (cadr (nth i (cadr v1_value_changes_split_start_ht))))))))
                                                               ;; 更新 value_changes_split_start_ht
                                                               ;; 如果从上次一信号变化到这一次信号变化之间没有分割
                                                               (cond ((< (/ (- simulation_time_new split_time) split_interval) 2)
                                                                      ;; 更新 value_changes_split_start_ht 为 v1_value_changes_split_end_ht
                                                                      (setf (gethash k1 (gethash k value_changes_split_start_ht)) (copy-tree v1_value_changes_split_end_ht)))
                                                                     (t
                                                                      ;; 从上次信号变化到当前时间戳，时间区间满足多次分割
                                                                      ;; 将旧信号列表赋值给value_changes_split_start_ht
                                                                      (setf (gethash k1 (gethash k value_changes_split_start_ht)) (copy-tree v1))
                                                                      ;; 读取旧时间戳信息
                                                                      (let* ((simulation_time_old (nth 0 (car v1)))
                                                                             ;; 读取旧值信息
                                                                             (scalar_value_old (nth 1 (car v1)))
                                                                             ;; 计算新的 split_time，为据当前时间戳刚好不满足一个时间间隔
                                                                             (split_time (- simulation_time_new (mod simulation_time_new split_interval))))
                                                                        ;; 更新value_changes_split_start_ht 的信号累计时间
                                                                        (incf (cadr (nth (cdr (assoc scalar_value_old '((#\0 . 0) (#\1 . 1) (#\x . 2) (#\z . 3))))
                                                                                         (cadr (gethash k1 (gethash k value_changes_split_start_ht)))))
                                                                              (- split_time simulation_time_old))
                                                                        ;; 更新value_changes_split_start_ht 的时间戳信息
                                                                        (setf (caar (gethash k1 (gethash k value_changes_split_start_ht))) split_time))))))
                                                         v))
                                            value_changes_ht)
                                   (setf (saif_struct-duration saifile) (list "DURATION" split_interval))
                                   (setf (saif_struct-instance_output saifile) (make_instance_output instance node_info_ht value_changes_split_range_ht instance_list))
                                   (do ((i split_time (+ i split_interval)))
                                       ;; 循环的最后更新 split_time
                                       ((> i simulation_time_new) (setf split_time i))
                                     (let ((saif_file (concatenate 'string
                                                                   (subseq vcd_file 0 (position #\. vcd_file :from-end t))
                                                                   (format nil "_~A_~A" (- i split_interval) i)
                                                                   "_vcd2saif.saif")))
                                       (append1f saif_file_list saif_file)
                                       (format t "SAIF file: ~A~%" saif_file)
                                       (file_print (make-pathname :name (concatenate 'string saif_folder saif_file)) saifile))))))
                           ;; 当单词以0,1,x,z字符起始时，为单变量变化信息
                           ((member (aref obj 0) '(#\0 #\1 #\x #\z))
                            (let* (;; 读取变量标识符
                                   (identifier_code (subseq obj 1))
                                   ;; 根据标识符从 value_changes_ht 中读取信号上次改变的时间戳
                                   (simulation_time_old (nth 0 (car (gethash 0 (gethash identifier_code value_changes_ht)))))
                                   ;; 根据标识符从 value_changes_ht 中读取信号的当前为止的值
                                   (scalar_value_old (nth 1 (car (gethash 0 (gethash identifier_code value_changes_ht)))))
                                   ;; 读取当前信号值
                                   (scalar_value_new (aref obj 0)))
                              ;; 更新 value_changes_ht 中的信号时间戳
                              (setf (nth 0 (car (gethash 0 (gethash identifier_code value_changes_ht)))) simulation_time_new)
                              ;; 更新 value_changes_ht 中的变量值信息
                              (setf (nth 1 (car (gethash 0 (gethash identifier_code value_changes_ht)))) scalar_value_new)
                              ;; 如果时间信息不为0
                              (cond ((/= 0 simulation_time_new)
                                     ;; 根据 scalar_value_old 确定索引位置
                                     ;; 根据索引为止确定 value_changes_ht 中需要改变的变量
                                     ;; 将持续时间叠加到对应的状态，完成累计状态更新
                                     (incf (cadr (nth (cdr (assoc scalar_value_old '((#\0 . 0) (#\1 . 1) (#\x . 2) (#\z . 3))))
                                                      (cadr (gethash 0 (gethash identifier_code value_changes_ht)))))
                                           (- simulation_time_new simulation_time_old))
                                     ;; 根据旧状态和当前状态，判断信号时候翻转
                                     (cond ((or (and (char= #\0 scalar_value_old)
                                                     (char= #\1 scalar_value_new))
                                                (and (char= #\1 scalar_value_old)
                                                     (char= #\0 scalar_value_new)))
                                            ;; 信号翻转，对value_changes_ht 中的信号翻转信息+1
                                            ;; 完成对value_changes_ht 的更新，更新当前时间戳，当前状态，累计状态，翻转次数
                                            (incf (cadr (nth 5 (cadr (gethash 0 (gethash identifier_code value_changes_ht))))))))))))
                           ;; 当单词以b字符起始时，为多变量变化信息
                           ((char= #\b (aref obj 0))
                            (let* (;; 从下一个单词读取变量标识符
                                   (identifier_code (car lines))
                                   ;; 对value_changes_ht 中保存 变量的二级哈希表进行计数，得到变量大小
                                   (size (hash-table-count (gethash identifier_code value_changes_ht)))
                                   ;; 读取多位变量值
                                   (vector_value (subseq obj 1))
                                   (vector_value_list nil))
                              ;; 更新lines
                              (setf lines (cdr lines))
                              ;; 得到当前多位变量长度
                              (let ((value_length (length vector_value)))
                                (do ((i 0 (1+ i)))
                                    ((= i value_length) 'done)
                                  ;; 将已有的多位变量从高位到低位添加到 vector_value_list 中
                                  (append1f vector_value_list (aref vector_value i)))
                                ;; 根据多位变量的size 进行补齐
                                (do ((i value_length (1+ i)))
                                    ((= i size) 'done)
                                  ;; 根据最高位决定具体赋值，延伸最高位
                                  (push (cdr (assoc (aref vector_value 0) '((#\0 . #\0) (#\1 . #\0) (#\x . #\x) (#\z . #\z)))) vector_value_list)))
                              ;; 反转 vector_value_list 变成从低到高
                              (setf vector_value_list (reverse vector_value_list))
                              (do ((i 0 (1+ i)))
                                  ((= i size) 'done)
                                ;; 更新value_changes_ht 中对应变量的所有信息
                                (let ((simulation_time_old (nth 0 (car (gethash i (gethash identifier_code value_changes_ht)))))
                                      (scalar_value_old (nth 1 (car (gethash i (gethash identifier_code value_changes_ht)))))
                                      (scalar_value_new (nth i vector_value_list)))
                                  (setf (nth 0 (car (gethash i (gethash identifier_code value_changes_ht)))) simulation_time_new)
                                  (setf (nth 1 (car (gethash i (gethash identifier_code value_changes_ht)))) scalar_value_new)
                                  (cond ((/= 0 simulation_time_new)
                                         (incf (cadr (nth (cdr (assoc scalar_value_old '((#\0 . 0) (#\1 . 1) (#\x . 2) (#\z . 3))))
                                                          (cadr (gethash i (gethash identifier_code value_changes_ht)))))
                                               (- simulation_time_new simulation_time_old))
                                         (cond ((or (and (char= #\0 scalar_value_old)
                                                         (char= #\1 scalar_value_new))
                                                    (and (char= #\1 scalar_value_old)
                                                         (char= #\0 scalar_value_new)))
                                                (incf (cadr (nth 5 (cadr (gethash i (gethash identifier_code value_changes_ht))))))))))))))
                           ;; 当单词以r字符起始时，为real变量变化信息，saif文件中并没有real变量，排除该信息
                           ((char= #\r (aref obj 0))
                            ;; 更新lines
                            (setf lines (cdr lines)))
                           ;; 当读取到$date时，为日期信息
                           ((equal "$date" obj)
                            ;; 从后续单词中读取日期信息，读取到$end单词为止
                            (do* ((date_data nil (concatenate 'string date_data " " obj))
                                  (obj (car lines) (car lines)))
                                 ((equal "$end" obj)
                                  (setf (cdr (assoc 'date header_info)) (concatenate 'string "\"" (subseq date_data 1) "\"")))
                              (setf lines (cdr lines)))
                            (setf (saif_struct-date saifile) (list "DATE" (cdr (assoc 'date header_info)))))
                           ;; 当读取到$version时，为版本信息
                           ((equal "$version" obj)
                            ;; 从后续单词中读取版本信息，读取到$end为止
                            (do* ((version_data nil (concatenate 'string version_data " " obj))
                                  (obj (car lines) (car lines)))
                                 ((equal "$end" obj)
                                  (setf (cdr (assoc 'version header_info)) (concatenate 'string "\"" (subseq version_data 1) "\"")))
                              (setf lines (cdr lines)))
                            (setf (saif_struct-version saifile) (list "VERSION" (cdr (assoc 'version header_info)))))
                           ;; 当读取到$timescale时，为时间分辨率信息
                           ((equal "$timescale" obj)
                            (do* ((timescale_data nil (concatenate 'string timescale_data " " obj))
                                  (obj (car lines) (car lines)))
                                 ((equal "$end" obj) (setf (cdr (assoc 'timescale header_info)) (concatenate 'string
                                                                                                             (subseq (subseq timescale_data 1) 0 (position-if #'alpha-char-p (subseq timescale_data 1)))
                                                                                                             " "
                                                                                                             (subseq (subseq timescale_data 1) (position-if #'alpha-char-p (subseq timescale_data 1))))))
                              (setf lines (cdr lines)))
                            (setf (saif_struct-timescale saifile) (list "TIMESCALE" (cdr (assoc 'timescale header_info)))))
                           ;; 当读取到scope时，可能为模型声明开始行
                           ((equal "$scope" obj)
                            ;; 读取模型名，构建模型变量instance
                            ;; instance为完整保存了所有所有instance嵌套信息的列表，如下
                            ;; (apatb_Blowfish_Init_Encrypt_top (AESL_inst_Blowfish_Init_Encrypt (bd_0_i (hls_inst (inst)))))
                            (setf instance (insert_module_instance instance instance_level (nth 1 lines)))
                            ;; 构建当前instance嵌套信息
                            ;; instance_list保存了当前instance的嵌套信息，也就是如何从完整instance列表中定位当前instance，如下
                            ;; (apatb_Blowfish_Init_Encrypt_top AESL_inst_Blowfish_Init_Encrypt bd_0_i hls_inst inst)
                            (append1f instance_list (nth 1 lines))
                            ;; instance_level保存了instance层级信息，此处有新instance，所以+1
                            (incf instance_level)
                            ;; 更新lines
                            (setf lines (cdddr lines)))
                           ;; 当读取到var时，为变量声明
                           ((equal "$var" obj)
                            (cond (;; 当读取到real变量时，跳过该real变量
                                   (equal "real" (car lines))
                                   (setf lines (cdr (cddddr lines))))
                                  (t
                                   (let (;; 读取变量标识符和变量名
                                         (identifier_code (nth 2 lines))
                                         (identifier (nth 3 lines)))
                                     ;; 更新value_changes_ht，以标识符identifier_code为key，赋值为一个新的哈希表
                                     (setf (gethash identifier_code value_changes_ht) (make-hash-table :test #'equal))
                                     (cond (;; 确定当前变量为单变量
                                            (and (equal "1" (nth 1 lines))
                                                 (equal "$end" (nth 4 lines)))
                                            ;; 更新node_info_ht，以当前instance定位列表为key，赋值为一个包含了变量名，变量标识符，和表示当前变量位数，此处为0，的列表，赋值方式为将该列表反向push到该哈希表值
                                            (append1f (gethash instance_list node_info_ht) (list (string_modify identifier) identifier_code 0))
                                            ;; 更新哈希表value_changes_ht中以标识符为key，的哈希表，以0为key，赋值为变量变化信息列表，0表示只有1位，是单变量
                                            ;; 如此，哈希表value_changes_ht以标识符为一级key，以变量位数为二级key，二级值中储存了变量变化信息
                                            (setf (gethash 0 (gethash identifier_code value_changes_ht)) (list (list 0 "T?") (list (list "T0" 0) (list "T1" 0) (list "TX" 0) (list "TZ" 0) (list "TB" 0) (list "TC" 0))))
                                            ;; 更新lines
                                            (setf lines (cdr (cddddr lines))))
                                           (t
                                            ;; 多位变量处理
                                            (let ((start 0)
                                                  (end 0))
                                              (cond (;; 当为类似integer类的多位变量时
                                                     (equal "$end" (nth 4 lines))
                                                     ;; 起始为赋值为0
                                                     (setf start 0)
                                                     ;; 终止赋值为读取到的位数-1
                                                     (setf end (1- (read-from-string (nth 1 lines))))
                                                     ;; 更新lines
                                                     (setf lines (cdr (cddddr lines))))
                                                    (t
                                                     ;; 当为reg类变量时
                                                     (let ((index (nth 4 lines)))
                                                       ;; 从读取到的具体位数范围信息中读取起始位和终止位，忽视读取到的位数信息
                                                       (setf start (read-from-string (subseq index (1+ (position #\: index)) (position #\] index))))
                                                       (setf end (read-from-string (subseq index (1+ (position #\[ index)) (position #\: index)))))
                                                     ;; 更新lines
                                                     (setf lines (cddr (cddddr lines)))))
                                              ;; 根据起始位和终止位更新node_info_ht和value_changes_ht
                                              (do ((i start (1+ i)))
                                                  ((> i end) 'done)
                                                (append1f (gethash instance_list node_info_ht) (list (string_modify (concatenate 'string identifier (format nil "\[~A\]" i))) identifier_code (- i start)))
                                                (setf (gethash (- i start) (gethash identifier_code value_changes_ht)) (list (list 0 "T?") (list (list "T0" 0) (list "T1" 0) (list "TX" 0) (list "TZ" 0) (list "TB" 0) (list "TC" 0))))))))))))
                           ((equal "$upscope" obj)
                            ;; 读取到instance定义结束，层级变量-1
                            (decf instance_level)
                            ;; 从当前instance定位列表删除当前instance
                            ;; 当读取到最后一个 upscope 时，instance_list 会被设置为 nil
                            (setf instance_list (subseq instance_list 0 (1- (length instance_list))))
                            ;; 更新lines
                            (setf lines (cdr lines)))
                           ((equal "$enddefinitions" obj)
                            ;; 读取到定义区结束信息，接下来会读取变量变化信息
                            ;; 根据哈希表value_changes_ht构建哈希表 value_changes_split_start_ht，value_changes_split_end_ht，value_changes_split_range_ht
                            ;; 这3个哈希表会有和value_changes_ht相同的结构
                            (maphash #'(lambda (k v)
                                         (setf (gethash k value_changes_split_start_ht) (make-hash-table :test #'equal))
                                         (setf (gethash k value_changes_split_end_ht) (make-hash-table :test #'equal))
                                         (setf (gethash k value_changes_split_range_ht) (make-hash-table :test #'equal))
                                         (maphash #'(lambda (k1 v1)
                                                      (setf (gethash k1 (gethash k value_changes_split_start_ht)) (copy-tree v1))
                                                      (setf (gethash k1 (gethash k value_changes_split_end_ht)) (copy-tree v1))
                                                      (setf (gethash k1 (gethash k value_changes_split_range_ht)) (copy-tree v1)))
                                                  v))
                                     value_changes_ht)
                            ;; 更新lines
                            (setf lines (cdr lines)))
                           ((equal "dumpvars" obj))
                           ((equal "dumpoff" obj))))))))
    (cond ((and (/= 0 simulation_time)
                (> simulation_time simulation_time_new))
           (setf simulation_time_new simulation_time)))
    (maphash #'(lambda (k v)
                 (maphash #'(lambda (k1 v1)
                              (let* ((simulation_time_old (nth 0 (car v1)))
                                     (scalar_value_old (nth 1 (car v1))))
                                (incf (cadr (nth (cdr (assoc scalar_value_old '((#\0 . 0) (#\1 . 1) (#\x . 2) (#\z . 3))))
                                                 (cadr (gethash k1 (gethash k value_changes_ht)))))
                                      (- simulation_time_new simulation_time_old))
                                (setf (caar (gethash k1 (gethash k value_changes_ht))) simulation_time_new)
                                ;; 如果分割未完成，更新 value_changes_split_range_ht
                                (cond ((and (/= 0 split_interval)
                                            (< (- split_time split_interval) simulation_time_new))
                                       (let ((v1_value_changes_split_end_ht (gethash k1 (gethash k value_changes_ht)))
                                             (v1_value_changes_split_start_ht (gethash k1 (gethash k value_changes_split_start_ht))))
                                         (setf (car (gethash k1 (gethash k value_changes_split_range_ht))) (list (list (caar v1_value_changes_split_start_ht) (caar v1_value_changes_split_end_ht))
                                                                                                                 (list (cadar v1_value_changes_split_start_ht) (cadar v1_value_changes_split_end_ht))))
                                         (do ((i 0 (1+ i)))
                                             ((= i 6) 'done)
                                           (setf (cadr (nth i (cadr (gethash k1 (gethash k value_changes_split_range_ht)))))
                                                 (- (cadr (nth i (cadr v1_value_changes_split_end_ht)))
                                                    (cadr (nth i (cadr v1_value_changes_split_start_ht)))))))))))
                          v))
             value_changes_ht)
    ;; 如果分割未完成，输出最后一个分割 SAIF 文件
    (cond ((and (/= 0 split_interval)
                (< (- split_time split_interval) simulation_time_new))
           (setf (saif_struct-duration saifile) (list "DURATION" (- simulation_time_new (- split_time split_interval))))
           (setf (saif_struct-instance_output saifile) (make_instance_output instance node_info_ht value_changes_split_range_ht instance_list))
           (let ((saif_file (concatenate 'string
                                         (subseq vcd_file 0 (position #\. vcd_file :from-end t))
                                         (format nil "_~A_~A" (- split_time split_interval) simulation_time_new)
                                         "_vcd2saif.saif")))
             (append1f saif_file_list saif_file)
             (format t "SAIF file: ~A~%" saif_file)
             (file_print (make-pathname :name (concatenate 'string saif_folder saif_file)) saifile))))
    ;; 输出完整的saif 文件
    (setf (saif_struct-duration saifile) (list "DURATION" simulation_time_new))
    (setf (saif_struct-instance_output saifile) (make_instance_output instance node_info_ht value_changes_ht instance_list))
    (let ((saif_file (concatenate 'string
                                  (subseq vcd_file 0 (position #\. vcd_file :from-end t))
                                  "_vcd2saif.saif")))
      (push saif_file saif_file_list)
      (format t "SAIF file: ~A~%" saif_file)
      (file_print (make-pathname :name (concatenate 'string saif_folder saif_file)) saifile))
    ;; 当时间间隔不为0，输出电力报告脚本
    (cond ((/= 0 split_interval)
           (let ((power_analysis_script (concatenate 'string (subseq vcd_file 0 (position #\. vcd_file :from-end t)) "_vcd2saif.tcl")))
             (format t "Power analysis script: ~A~%" power_analysis_script)
             (format t "Saif file count: ~A~%" (length saif_file_list))
             (with-open-file (str (make-pathname :name power_analysis_script)
                                  :direction :output :if-exists :supersede)
               (format str "set_units -current uA -voltage uV -power uW~%")
               (format str "set_operating_conditions -process maximum~%")
               (dolist (obj saif_file_list)
                 (format str "read_saif {~A~A}~%" saif_folder obj)
                 (format str "report_power -file {~A~A.txt}~%" power_report_folder (subseq obj 0 (position #\. obj :from-end t))))))
           (cond ((/= 0 tcl_count)
                  (let* ((saif_file_list_len (length saif_file_list))
                         (saif_file_list_count (floor (/ saif_file_list_len tcl_count))))
                    (do* ((start 0 end)
                          (end saif_file_list_count (+ end saif_file_list_count)))
                         ((> end saif_file_list_len) 'done)
                      (cond ((> (+ end saif_file_list_count) saif_file_list_len)
                             (setf end saif_file_list_len)))
                      (let* ((saif_file_list_sub (subseq saif_file_list start end))
                             (power_analysis_script (concatenate 'string
                                                                 (subseq vcd_file 0 (position #\. vcd_file :from-end t))
                                                                 "_" (write-to-string start)
                                                                 "_" (write-to-string end) "_vcd2saif.tcl")))
                        (setf start end)
                        (format t "Split Power analysis script: ~A~%" power_analysis_script)
                        (with-open-file (str (make-pathname :name power_analysis_script)
                                             :direction :output :if-exists :supersede)
                          (format str "set_units -current uA -voltage uV -power uW~%")
                          (format str "set_operating_conditions -process maximum~%")
                          (dolist (obj saif_file_list_sub)
                            (format str "read_saif {~A~A}~%" saif_folder obj)
                            (format str "report_power -file {~A~A.txt}~%" power_report_folder (subseq obj 0 (position #\. obj :from-end t))))))))))))
    (format t "Final RUN TIME: ~f S~%" (float (/ (- (GET-INTERNAL-REAL-TIME) current_time) INTERNAL-TIME-UNITS-PER-SECOND)))))
;;; ===================================== 主函数结束 =====================================
;;; ===================================== 函数定义区结束 =====================================
