SELECT FORMAT(trans_date,'yyyy-MM') as month, 
country,count(id) as trans_count,
SUM(CASE WHEN state = 'approved' THEN 1 ELSE 0 END) as approved_count,
SUM(amount) AS trans_total_amount,
SUM(CASE WHEN state = 'approved' THEN amount ELSE 0 END) as approved_total_amount
FROM transactions
GROUP BY FORMAT(trans_date,'yyyy-MM'), country
ORDER BY FORMAT(trans_date,'yyyy-MM');
-- ye dhyaan rkhna format ka yhi syntax hai