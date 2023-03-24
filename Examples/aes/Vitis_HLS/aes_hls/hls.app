<project xmlns="com.autoesl.autopilot.project" name="aes_hls" top="aes_encrypt">
    <includePaths/>
    <libraryPaths/>
    <Simulation>
        <SimFlow name="csim" clean="true" csimMode="0" lastCsimMode="0"/>
    </Simulation>
    <files xmlns="">
        <file name="../src/aes_tb.h" sc="0" tb="1" cflags=" -Wno-unknown-pragmas" csimflags=" -Wno-unknown-pragmas" blackbox="false"/>
        <file name="../src/aes_tb.cpp" sc="0" tb="1" cflags=" -Wno-unknown-pragmas" csimflags=" -Wno-unknown-pragmas" blackbox="false"/>
        <file name="aes_hls/src/encrypt/aes_enc_func.h" sc="0" tb="false" cflags="" csimflags="" blackbox="false"/>
        <file name="aes_hls/src/encrypt/aes_enc_func.cpp" sc="0" tb="false" cflags="" csimflags="" blackbox="false"/>
        <file name="aes_hls/src/encrypt/aes_enc.h" sc="0" tb="false" cflags="" csimflags="" blackbox="false"/>
        <file name="aes_hls/src/encrypt/aes_enc.cpp" sc="0" tb="false" cflags="" csimflags="" blackbox="false"/>
        <file name="aes_hls/src/decrypt/aes_dec_func.h" sc="0" tb="false" cflags="" csimflags="" blackbox="false"/>
        <file name="aes_hls/src/decrypt/aes_dec_func.cpp" sc="0" tb="false" cflags="" csimflags="" blackbox="false"/>
        <file name="aes_hls/src/decrypt/aes_dec.h" sc="0" tb="false" cflags="" csimflags="" blackbox="false"/>
        <file name="aes_hls/src/decrypt/aes_dec.cpp" sc="0" tb="false" cflags="" csimflags="" blackbox="false"/>
        <file name="aes_hls/src/common/aes_TypeConvert.h" sc="0" tb="false" cflags="" csimflags="" blackbox="false"/>
        <file name="aes_hls/src/common/aes_TypeConvert.cpp" sc="0" tb="false" cflags="" csimflags="" blackbox="false"/>
        <file name="aes_hls/src/common/aes_KeySchedule.h" sc="0" tb="false" cflags="" csimflags="" blackbox="false"/>
        <file name="aes_hls/src/common/aes_KeySchedule.cpp" sc="0" tb="false" cflags="" csimflags="" blackbox="false"/>
        <file name="aes_hls/src/common/aes_AddRoundKey.h" sc="0" tb="false" cflags="" csimflags="" blackbox="false"/>
        <file name="aes_hls/src/common/aes_AddRoundKey.cpp" sc="0" tb="false" cflags="" csimflags="" blackbox="false"/>
    </files>
    <solutions xmlns="">
        <solution name="solution1" status="active"/>
        <solution name="solution1" status="active"/>
        <solution name="solution1" status="active"/>
    </solutions>
</project>

