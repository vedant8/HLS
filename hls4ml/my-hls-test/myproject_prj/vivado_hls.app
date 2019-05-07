<AutoPilot:project xmlns:AutoPilot="com.autoesl.autopilot.project" projectType="C/C++" name="myproject_prj" top="myproject">
    <Simulation argv="">
        <SimFlow name="csim" setup="false" optimizeCompile="false" clean="false" ldflags="" mflags=""/>
    </Simulation>
    <includePaths/>
    <libraryFlag/>
    <files>
        <file name="../../myproject_test.cpp" sc="0" tb="1" cflags=" -IG:/Physics/Particle_Physics/B-Physics/hls4ml-bdt/bdt_utils  -std=c++0x"/>
        <file name="firmware/myproject.cpp" sc="0" tb="false" cflags="-IG:/Physics/Particle_Physics/B-Physics/hls4ml-bdt/bdt_utils -std=c++0x"/>
    </files>
    <solutions>
        <solution name="solution1" status=""/>
    </solutions>
</AutoPilot:project>

