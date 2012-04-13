#!/bin/bash
nodei=1000
minedges=`echo "$nodei-1" | bc`
maxedges=`echo "(($nodei*$nodei)-$nodei)/2" | bc`
echo "$nodei $maxedges"
for (( i = $minedges; i < $maxedges; i++ )); do
	echo "$i,`java GraphTest $nodei $i 100 0`"
done
