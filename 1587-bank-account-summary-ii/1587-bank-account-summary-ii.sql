# Write your MySQL query statement below
select name as 'Name',sum(amount)as 'balance' from users join transactions on users.account=transactions.account group by users.name having sum(amount)>10000 