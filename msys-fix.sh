#!/bin/bash
if [ $# -ge 1 ]
then
	proj_name="$1"
else
	proj_name="gtk-test"
fi

fix_file="CMakeFiles/${proj_name}.dir/flags.make"

if [ ! -f "${fix_file}" ]
then
	echo "${fix_file} not found!"
fi
sed -iv "s/\/home\/liujinsong\/gtk\/gtk-tutorials\/${proj_name}\/D:\/msys64//g" "${fix_file}"
