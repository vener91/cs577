#!/bin/bash
rm -rf ./results/*
part3.sh > ./results/part3.csv &
part4_10.sh > ./results/part4_10.csv &
part4_1000.sh > ./results/part4_1000.csv &
part4_50.sh > ./results/part4_50.csv &
part5.sh > ./results/part5.csv &
