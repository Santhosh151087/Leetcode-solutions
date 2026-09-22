# Write your MySQL query statement below
select ROUND(count(player_id) / (select count(DISTINCT player_id) from Activity ) , 2) as  fraction 
from Activity
where (event_date , player_id) in (
select date_add(min(event_date) , INTERVAL 1 DAY) , player_id
from Activity
group by player_id
);

