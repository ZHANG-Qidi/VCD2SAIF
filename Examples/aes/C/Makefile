#目标文件生成在目标文件夹中对应源文件夹的文件夹
TARGET  = aes
CC      = gcc
CPP     = cpp
EXTRA_CFLAGS += -std=c11
CFLAGS  += -Wall -g
CFLAGS  += $(EXTRA_CFLAGS)
SRC_DIR = . src
OBJ_DIR = Debug/
C_SRC   = $(wildcard $(SRC_DIR:%=%/*.c))
C_OBJ   = $(C_SRC:%.c=$(OBJ_DIR)%.o)
C_DEP   = $(C_SRC:%.c=$(OBJ_DIR)%.d)
$(TARGET) : $(C_OBJ) $(C_DEP)
	$(CC) $(CFLAGS) -o $(TARGET) $(C_OBJ)
$(C_DEP): $(OBJ_DIR)%.d : %.c
	@mkdir -p $(dir $@)
	$(CPP) $(EXTRA_CFLAGS) -MM $< > $@
	@sed -r -i 's|^(\w+)\.o[ :]*|$(@:.d=.o) : |' $@
$(C_OBJ) : $(OBJ_DIR)%.o : %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@
ifneq ($(MAKECMDGOALS), clean)
-include $(C_DEP)
endif
.PHONY : clean
clean :
	-rm $(TARGET) $(C_OBJ) $(C_DEP)
