SELECT movies.title FROM movies, ratings, stars, people WHERE stars.person_id = people.id AND stars.movie_id = ratings.movie_id AND ratings.movie_id = movies.id AND people.name = "Chadwick Boseman" ORDER BY ratings.rating DESC LIMIT 5;