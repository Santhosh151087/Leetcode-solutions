select max(t1.num) as num from (
select num from 
Mynumbers 
group by num
having count(num) =1
) as t1;