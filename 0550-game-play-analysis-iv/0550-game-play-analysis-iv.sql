# Write your MySQL query statement below
with Table_1 As(
    Select player_id,min(event_date) as event_date from Activity group by player_id
),Table_3 As(
    Select distinct T1.player_id from Table_1 T1 Join Activity T2 On
        T1.player_id=T2.player_id
        and
        DATE_SUB(T2.event_date,INTERVAL 1 DAY)=T1.event_date
    
) Select ROUND((Select count(*) from Table_3 )/(Select count(distinct(player_id)) from Activity),2) as fraction;


  