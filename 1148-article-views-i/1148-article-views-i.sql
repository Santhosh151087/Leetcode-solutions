# Write your MySQL query statement below
select DISTINCT viewer_id as id from Views 
where author_id = viewer_id 
order by viewer_id;