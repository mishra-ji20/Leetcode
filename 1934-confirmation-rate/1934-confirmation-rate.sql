# Write your MySQL query statement below
With Table1 As(
Select su.user_id,count(1) As TotalCount from Signups su left outer join Confirmations con
    on
    su.user_id= con.user_id
    group by(user_id)
),Table2 as(
    Select su.user_id,count(1) As ConfirmedCount from Signups su inner join Confirmations con
    on
    su.user_id= con.user_id
    where con.action='confirmed'
    group by(user_id)
)Select t1.user_id,
Case
    When (ConfirmedCount/TotalCount) is Null Then 0.00
    Else Round((ConfirmedCount/TotalCount),2)
End As confirmation_rate
from Table1 t1 left outer join Table2 t2 on t1.user_id =t2.user_id;

