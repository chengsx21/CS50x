SELECT p1.name
  FROM people p1, people p2, stars s1, stars s2
 WHERE s1.person_id = p1.id
   AND s2.person_id = p2.id
   AND p1.id != p2.id
   AND s1.movie_id = s2.movie_id
   AND p2.name = 'Kevin Bacon';