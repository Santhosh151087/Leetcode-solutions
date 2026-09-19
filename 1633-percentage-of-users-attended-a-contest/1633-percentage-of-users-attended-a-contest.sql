SELECT contest_id , ROUND(((count(contest_id)*100)/(select count(user_id) from Users)),2) as percentage 
from Register
group by contest_id
order by percentage DESC , contest_id