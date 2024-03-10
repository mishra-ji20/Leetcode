# Write your MySQL query statement below
Select empuni.unique_id,emp.name from Employees emp left outer join EmployeeUni empuni 
on emp.id=empuni.id;