# Write your MySQL query statement below
select Emp.name,Bonus.bonus from Employee Emp left join Bonus on Emp.empId= Bonus.empId where Bonus.bonus<1000 or Bonus.bonus is null;
