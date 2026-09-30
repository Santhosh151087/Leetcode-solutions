select person_name from 
(select *  , SUM(weight) over (order by turn)  as total_weight
from Queue) as t1
where total_weight<=1000
order by total_weight DESC
limit 1 ;