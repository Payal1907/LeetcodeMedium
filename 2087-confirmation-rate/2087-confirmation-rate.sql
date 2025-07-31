SELECT S.user_id, 
ROUND(ISNULL(SUM(CASE WHEN action='confirmed' THEN 1 END)*1.00/COUNT(*),0),2) AS confirmation_rate
FROM
Signups S
LEFT JOIN
Confirmations C
ON
S.user_id=C.user_id
GROUP BY S.user_id
;
-- sum() for all the cases having action ="confirmed" we count tem
-- isnull, if is null then 0, otherwise the left value
-- round of to two decimal places
