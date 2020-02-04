#!/bin/sh
classes_images=40
nb_image=9
p=0

for i in `seq 1 $classes_images`
do
	
	       
		for j in `seq 0 $nb_image`

		do
	for k in `seq 1 $classes_images`
		do
		#match_ok=0
			for l in `seq 0 $nb_image`
			do				
						 
#echo "valeur" $p > res.txt
./match -im1 base_apprentissage/obj$k"__"$((10 * $l)).pgm -k1 base_apprentissage_key/obj$k"__"$((10 * $l)).key -im2 base_test/obj$i"__"$((5 + 10 * $j)).pgm -k2 base_test_key/obj$i"__"$((5 + 10 * $j)).key >> img/img$p.pgm

				p=$(($p+1)) 			
				
			done
		done
		
	done

	
done

