# Write your MySQL query statement below
select score ,dense_rank() over (
    
    order by score DESC
) as 'rank'
from Scores