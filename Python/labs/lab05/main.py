import asyncio

from api_worker import get_trending
from output_formater import generate_output
from argument_parser import parse_args

async def main():
    type_media, time_window, output_format = parse_args()
    trending_data = await get_trending(type_media, time_window, loop)
    sorted_data = sorted(trending_data["results"], key=lambda x: x["vote_average"], reverse=True)
    
    output_data = [{"title": item["name" if type_media == "tv" else "title"], "rating": item["vote_average"]} for item in sorted_data]
    generate_output(output_data, output_format)
    

if __name__ == "__main__":
    loop = asyncio.get_event_loop()
    loop.run_until_complete(main())