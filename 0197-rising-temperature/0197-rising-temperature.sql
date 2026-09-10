-- # Write your MySQL query statement below
-- SELECT id FROM (
--     select id,  temperature ,
--     LAG(temperature) OVER (ORDER BY recordDate) AS prev_temp
--     from  Weather
-- ) w 
-- -- this is the alias of subquery
-- where temperature > prev_temp;

SELECT today.id
FROM Weather today 
JOIN Weather yesterday 
ON DATEDIFF(today.recordDate , yesterday.recordDate) = 1
AND today.temperature > yesterday.temperature;