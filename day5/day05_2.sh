#!/bin/bash

echo -n "Enter the year: "
read y
year=$y
y=$(( $y % 4))
if  [ $y -eq 0 ]
then
   echo "$year is leap"
else
   echo "$year is not leap"
fi
