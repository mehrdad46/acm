#!/bin/bash

# sudo cp c.bash /bin/

if [[ -e $1 ]]; then
	echo "$1 already exists!";
	exit 1;
fi;
pr=`basename $1`
mkdir $1
cat >$1/makefile <<EOF
n = $pr
\$n : \$n.cpp
	g++ \$n.cpp -o \$n -O2 -Wall -g
EOF

cat >$1/$pr.cpp ~/Templates/acm.cpp
