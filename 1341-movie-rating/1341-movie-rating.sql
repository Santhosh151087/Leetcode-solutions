
(select DISTINCT t1.name as results from Users t1
LEFT JOIN MovieRating t2
ON t1.user_id = t2.user_id
group by t1.user_id
having count(t2.movie_id) = (
select count(movie_id) as count from MovieRating
group by user_id
order by count  desc
limit 1 
)
order by results
limit 1)

union all

(select DISTINCT t1.title as results from Movies t1
LEFT JOIN MovieRating t2
ON t1.movie_id = t2.movie_id
where t2.created_at between '2020-02-01' and '2020-02-29' 
GROUP BY t1.movie_id 
having avg(t2.rating) = (
    select avg(rating) as rating from MovieRating
where created_at between '2020-02-01' and '2020-02-29'
group by movie_id 
order by rating desc
limit 1
)
order by results
limit 1);

