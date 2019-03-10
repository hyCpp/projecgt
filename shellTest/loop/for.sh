#! /bin/sh
for i in old.xml
do
    echo $i
    mv $i $i.old
    sed 's/typeId/taskId/g' < $i.old > $i
done

