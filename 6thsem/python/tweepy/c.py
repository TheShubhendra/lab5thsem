import tweepy
from decouple import config

BEARER_TOKEN = config("BEARER_TOKEN")


client = tweepy.Client(bearer_token=BEARER_TOKEN)

query = "Odisha"  # Replace with your search term

tweets = client.search_recent_tweets(query=query, max_results=15)

# Print tweets
for tweet in tweets.data:
    print(f"Tweet: {tweet.text}\n")