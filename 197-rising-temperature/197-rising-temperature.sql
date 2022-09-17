# Write your MySQL query statement below
SELECT W1.ID FROM 
WEATHER W1,WEATHER W2
WHERE W1.TEMPERATURE>W2.TEMPERATURE AND 
w2.recordDate=date_sub(w1.recordDate, interval 1 day );