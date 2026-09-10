Select start.machine_id , ROUND(AVG(end.timestamp - start.timestamp) , 3) AS processing_time 
from Activity start
JOIN Activity end
ON start.process_id = end.process_id and start.machine_id = end.machine_id
where start.activity_type = 'start' and end.activity_type = 'end' 
group by start.machine_id; 