./gen 1 20 40 200 1  > testcase/00.in
./gen 1 20 40 200 2  > testcase/01.in
./gen 1 20 40 200 3  > testcase/02.in
./gen 1 30 50 200 81 > testcase/03.in

for i in `seq -f %02g 4 11`;
do
  ./gen 2 30 50 200 $i > testcase/$i.in
done

for i in `seq -f %02g 12 19`;
do
  ./gen 3 30 50 200 $i > testcase/$i.in
done
