import csv
from pprint import pprint
import requests
import json

titles = ['Roma', 'El+Camino', 'Get+Out', 'Parasite', 'The+Irishman',
          'Superbad', 'Call+Me+by+Your+Name', 'Psycho', 'Black+Panther',
          'Moonlight', 'Joker', 'Lady+Bird', 'Midsommar', 'Taxi+Driver',
          'The+Godfather', 'Once+Upon+a+Time+in+Hollywood', 'Boyhood',
          'Pulp+Fiction', 'American+Psycho', 'Always+be+My+Maybe',
          'Ex+Machina', 'Spotlight', 'Zero+Dark+Thirty', 'Booksmart',
          'The+Witch', 'Gone+Girl', 'The+King']

genres = {'Action': 3,
          'Adventure': 2,
          'Biography': -1,
          'Comedy': 4,
          'Crime': -2,
          'Drama': -1,
          'History': -1,
          'Horror': -4,
          'Mystery': -2,
          'Romance': +2,
          'Sci-Fi': +2,
          'Thriller': -2,
          'War': -1}

with open('warianty2.csv', mode='w') as csv_file:
    fieldnames = ['Title', 'Runtime', 'Year', 'Genre', 'Ease', 'Metascore', 'imdbRating']
    writer = csv.DictWriter(csv_file, fieldnames=fieldnames)
    writer.writeheader()
    for title in titles:
        request = requests.get('http://www.omdbapi.com/?apikey=9d3b578b&t=' + title)

        json_data = request.text

        parsed_json = json.loads(json_data)
        parsed_json = {key: value for key, value in parsed_json.items() if key in fieldnames}
        parsed_json['Runtime'] = parsed_json['Runtime'][:-4]
        film_genres = parsed_json['Genre'].split(', ')
        parsed_json['Ease'] = sum([genres[f] for f in film_genres])
        if title == 'El+Camino':
            parsed_json['Metascore'] = 72
        writer.writerow(parsed_json)
