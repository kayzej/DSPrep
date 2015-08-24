#!/bin/bash
echo "INPUT"
cat inputs/input4.txt

echo

echo "REPLACE"
./main.exe inputs/input4.txt myOutputs/output4_replace.txt replace X 0
cat myOutputs/output4_replace.txt

echo

echo "DILATE"
./main.exe inputs/input4.txt myOutputs/output4_dilation.txt dilation X
cat myOutputs/output4_dilation.txt

echo

echo "ERODE"
./main.exe inputs/input4.txt myOutputs/output4_erosion.txt erosion X ./
cat myOutputs/output4_erosion.txt

echo

echo "FLOODFILL"
./main.exe inputs/input4.txt myOutputs/output4_floodfill.txt floodfill 2 10 0
cat myOutputs/output4_floodfill.txt

echo

echo "OPENING"
./main.exe myOutputs/output4_erosion.txt myOutputs/output4_opening.txt dilation X
cat myOutputs/output4_opening.txt
echo 

echo "CLOSING"
./main.exe myOutputs/output4_dilation.txt myOutputs/output4_closing.txt erosion X \.
cat myOutputs/output4_closing.txt