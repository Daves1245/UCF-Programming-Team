contests=$(ls)
for x in $contests; do
    problms=$(ls)
    for y in $problems; do
        echo "entering $(basename $y)"
        cd $(basename $y)
        cf test
        cd -
    done
done
