function(add_runnable name)
	add_executable(${name} ${ARGN})
	add_custom_target(run_${name} $<TARGET_FILE:${name}>)
endfunction()

add_runnable(hist main.cpp)

#target_link_libraries(hist PRIVATE benchmark::benchmark)
