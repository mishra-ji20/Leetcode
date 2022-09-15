# Write your MySQL query statement below
select name as Customers from customers where id not in(select distinct customerId  from orders);
