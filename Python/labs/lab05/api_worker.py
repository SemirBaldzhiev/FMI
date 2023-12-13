import requests
import os
from dotenv import load_dotenv

load_dotenv()

TMDB_API_KEY = os.getenv("TMDB_API_KEY")

async def get_trending(type_media: str, time_window: str, loop):
    url = f"https://api.themoviedb.org/3/trending/{type_media}/{time_window}?language=en-US"
    headers = {"Authorization": f"Bearer {TMDB_API_KEY}"}
    response = await loop.run_in_executor(None, lambda: requests.get(url, headers=headers))
    return response.json()
