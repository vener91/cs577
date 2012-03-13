#!/bin/bash
testVal=( 10000 20000 30000 40000 50000 60000 70000 80000 90000 100000 110000 120000 130000 140000 150000 160000 170000 180000 190000 200000)
rm -rf ./results/*
echo "Skiplist"
for i in "${testVal[@]}"
do
	/usr/bin/time main -i 0 -d ./sample/u_$i 2>> ./results/skiplist
	cat ./results/skiplist | grep elapsed | awk '{ print $3 }' | sed s/elapsed//g > ./results/skiplist 

done
echo "Linked List"
for i in "${testVal[@]}"
do
	/usr/bin/time main -i 1 -d ./sample/u_$i 2>> ./results/linkedlist
	cat ./results/linkedlist | grep elapsed | awk '{ print $3 }' | sed s/elapsed//g > ./results/linkedlist 
done
echo "Array List"
for i in "${testVal[@]}"
do
	/usr/bin/time main -i 2 -d ./sample/u_$i 2>> ./results/arraylist
	cat ./results/arraylist | grep elapsed | awk '{ print $3 }' | sed s/elapsed//g > ./results/arraylist 
done
