#!/bin/sh

for file in coil-100/*0.png
do
  convert $file base_apprentissage/`basename $file .png`.pgm
  ./sift < base_apprentissage/`basename $file .png`.pgm > base_apprentissage_key/`basename $file .png`.key 2>/dev/null
done
echo "base apprentissage et des keypoints ok."

for file in coil-100/*5.png
do
  convert $file base_test/`basename $file .png`.pgm
  ./sift < base_test/`basename $file .png`.pgm > base_test_key/`basename $file .png`.key 2>/dev/null
done
echo "base de test et des keypoints ok."
