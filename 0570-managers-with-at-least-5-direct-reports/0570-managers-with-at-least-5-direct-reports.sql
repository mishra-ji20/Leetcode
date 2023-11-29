# Write your MySQL query statement below
# With countm as(
#     Select managerId from Employee group by managerId where count(managerId)>=5 
# )
# Select name from employee inner join countm on countm.managerId=employee.id;
 
 
with table_1 as (Select managerId , count(managerId) as CountM from employee group by managerId),table_2 as(select managerId from table_1 where CountM>=5) 
Select name from employee inner join table_2 on table_2.managerId=employee.id;