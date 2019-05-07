#################
#    HLS4ML
#################
open_project -reset myproject_prj
set_top myproject
add_files firmware/myproject.cpp -cflags "-I[file normalize ../../bdt_utils] -std=c++0x"
add_files -tb myproject_test.cpp -cflags "-I[file normalize ../../bdt_utils] -std=c++0x"
#add_files -tb tb_data
open_solution -reset "solution1"
set_part {xc7vx690tffg1927-2}
create_clock -period 5 -name default
csim_design
csynth_design
export_design -format ip_catalog
exit
