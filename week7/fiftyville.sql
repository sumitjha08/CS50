-- Keep a log of any SQL queries you execute as you solve the mystery.

-- We know the theft took place on Humphrey Street on July 28

SELECT description FROM crime_scene_reports
WHERE month = 7 AND day = 28 AND street = "Humphrey Street";

SELECT transcript FROM interviews
WHERE month = 7 AND day = 28 AND transcript LIKE "%bakery%";

SELECT license_plate
FROM bakery_security_logs
WHERE month = 7
AND day = 28
AND hour = 10
AND minute BETWEEN 15 AND 25
AND activity = 'exit';

SELECT name
FROM people
WHERE license_plate IN (
    SELECT license_plate
    FROM bakery_security_logs
    WHERE month = 7
    AND day = 28
    AND hour = 10
    AND minute BETWEEN 15 AND 25
    AND activity = 'exit'
);

SELECT account_number
FROM atm_transactions
WHERE month = 7
AND day = 28
AND atm_location = 'Leggett Street'
AND transaction_type = 'withdraw';

SELECT name
FROM people
JOIN bank_accounts
ON people.id = bank_accounts.person_id
WHERE account_number IN (
    SELECT account_number
    FROM atm_transactions
    WHERE month = 7
    AND day = 28
    AND atm_location = 'Leggett Street'
    AND transaction_type = 'withdraw'
);

SELECT caller, receiver
FROM phone_calls
WHERE month = 7
AND day = 28
AND duration < 60;

SELECT *
FROM flights
WHERE month = 7
AND day = 29
ORDER BY hour, minute
LIMIT 1;
SELECT city
FROM airports
WHERE id = (
    SELECT destination_airport_id
    FROM flights
    WHERE month = 7
    AND day = 29
    ORDER BY hour, minute
    LIMIT 1
);

SELECT name
FROM people
JOIN passengers
ON people.passport_number = passengers.passport_number
WHERE flight_id = (
    SELECT id
    FROM flights
    WHERE month = 7
    AND day = 29
    ORDER BY hour, minute
    LIMIT 1
);

SELECT name
FROM people
WHERE phone_number = (
    SELECT receiver
    FROM phone_calls
    WHERE caller = (
        SELECT phone_number
        FROM people
        WHERE name = 'Bruce'
    )
    AND month = 7
    AND day = 28
    AND duration < 60
);

