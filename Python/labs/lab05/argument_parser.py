import sys

def parse_args():
    if len(sys.argv) != 4:
        print("Usage: python3 main.py <type_media> <time_window> <output_format>")
        exit(1)

    type_media = sys.argv[1]
    time_window = sys.argv[2]
    output_format = sys.argv[3]
    
    if type_media not in ["movie", "tv"]:
        print("Invalid type_media. Choose between 'movie' or 'tv'")
        exit(1)
    
    if time_window not in ["day", "week"]:
        print("Invalid time_window. Choose between 'day' or 'week'")
        exit(1)
    
    if output_format not in ["json", "csv"]:
        print("Invalid output_format. Choose between 'json' or 'csv'")
        exit(1)
    
    return type_media, time_window, output_format

