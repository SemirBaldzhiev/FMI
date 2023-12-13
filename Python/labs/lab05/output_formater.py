
import json
import csv

def generate_output(data, format):
    if format == "json":
        generate_json_output(data)
    else:
        generate_csv_output(data)
        

def generate_json_output(data):
    with open("output.json", "w") as json_file:
        json.dump(data, json_file, indent=4)
        
def generate_csv_output(data):
    with open("output.csv", "w") as csv_file:
            csv_writer = csv.DictWriter(csv_file, fieldnames=["title", "rating"])
            csv_writer.writeheader()
            csv_writer.writerows(data)
