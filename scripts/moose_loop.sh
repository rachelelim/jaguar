#!/bin/sh
# -*- coding: utf-8 -*-


counter=1
while [ $counter -le 5 ]
do
mpiexec -n 16 ./jaguar-opt input$counter.i
((counter++))
done
echo All done
