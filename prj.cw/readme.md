Клиент серверное приложение. Серверная часть отвечает на https запросы клиента.
REST API

В качестве базовой функциональности сервиса будет реализовано 7 базовых методов.

Для всех методов в случае корректного ответа ожидается ответ `HTTP 200 OK`.

1) ### POST /couriers
Для загрузки списка курьеров в систему запланирован описанный ниже интерфейс.

Обработчик принимает на вход список в формате json с данными о курьерах и графиком их работы.
Нпример: [
    {"district": 10,
    "time":"12:00-20:00",
    "type":"driver"
    },
    {"district": 1,
    "time":"22:20-06:00",
    "type":"walker"
    }
]
Курьеры работают только в заранее определенных районах, а также различаются по типу: пеший, велокурьер и 
курьер на автомобиле. От типа зависит объем заказов, которые перевозит курьер.
Районы задаются целыми положительными числами. График работы задается списком строк формата `HH:MM-HH:MM`.

2) ### GET /couriers/{courier_id}

Возвращает информацию о курьере с заданным courier_id а также его id в базе данных. Например: на http://127.0.0.1:8000/couriers/1
вернется
{
  "district":10,
  "id":1,
  "time":"12:00-20:00",
  "type":"driver"
}

3) ### GET /couriers

Возвращает информацию о всех курьерах. Например: на http://127.0.0.1:8000/couriers
вернется
[
  {
    "district":10,
    "id":1,
    "time":"12:00-20:00",
    "type":"driver"
  },
  {
    "district":1,
    "id":2,
    "time":"22:20-06:00",
    "type":"walker"
  }
]

4) ### POST /orders

Принимает на вход список с данными о заказах в формате json. У заказа отображаются характеристики — вес, район, 
время доставки.
Время доставки - строка в формате HH:MM-HH:MM, где HH - часы (от 0 до 23) и MM - минуты (от 0 до 59). Примеры: “09:00-11:00”, “12:00-23:00”, “00:00-23:59”.
[
    {
    "weight":10,
    "district":10,
    "time":"12:00-12:30"
    }
]


5) ### GET /orders/{order_id}

Возвращает информацию о заказе по его идентификатору, а также дополнительную информацию: id в базе данных и статус заказа(готов/не готов).
Например: на http://127.0.0.1:8000/orders/1
вернется
{
  "district":10,
  "id":1,
  "isready":false,
  "time":"12:00",
  "weight":10
}

6) ### GET /orders

Возвращает информацию о всех заказах.
[
  {
    "district":10,
    "id":1,
    "isready":false,
    "time":"12:00",
    "weight":10
  },
  {
    "district":10,
    "id":2,
    "isready":false,
    "time":"12:00-12:30",
    "weight":10
  }
]

7) ### POST /orders/complete

Принимает массив объектов, состоящий из id выполненных заказов, после отмечает, что заказ выполнен.

