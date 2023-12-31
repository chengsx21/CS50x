-- Keep a log of any SQL queries you execute as you solve the mystery.

-- 查看所有表
.tables
.schema

-- 查看当天犯罪记录
SELECT *
  FROM crime_scene_reports
 WHERE year = 2021
   AND month = 7
   AND day = 28
   AND street = "Humphrey Street";

-- 查看当天三位目击者关于小偷的采访记录
SELECT *
  FROM interviews
 WHERE year = 2021
   AND month = 7
   AND day = 28
   AND transcript LIKE "%thief%";

-- 线索1.
-- Sometime within ten minutes of the theft, I saw the thief
-- get into a car in the bakery parking lot and drive away.
-- If you have security footage from the bakery parking lot,
-- you might want to look for cars that left the parking lot
-- in that time frame.

SELECT name
  FROM people, bakery_security_logs
 WHERE year = 2021
   AND people.license_plate = bakery_security_logs.license_plate
   AND month = 7
   AND day = 28
   AND hour = 10
   AND minute > 15
   AND minute <= 25
   AND activity = "exit"
 ORDER BY name;

-- +---------+
-- |  name   |
-- +---------+
-- | Barry   |
-- | Bruce   |
-- | Diana   |
-- | Iman    |
-- | Kelsey  |
-- | Luca    |
-- | Sofia   |
-- | Vanessa |
-- +---------+

-- 线索2.
-- I don't know the thief's name, but it was someone I recognized.
-- Earlier this morning, before I arrived at Emma's bakery, I was
-- walking by the ATM on Leggett Street and saw the thief there
-- withdrawing some money.

SELECT name
  FROM people, bank_accounts, atm_transactions
 WHERE people.id = bank_accounts.person_id
   AND bank_accounts.account_number = atm_transactions.account_number
   AND year = 2021
   AND month = 7
   AND day = 28
   AND atm_location = "Leggett Street"
   AND transaction_type = "withdraw"
 ORDER BY name;

-- +---------+
-- |  name   |
-- +---------+
-- | Benista |
-- | Brooke  |
-- | Bruce   |
-- | Diana   |
-- | Iman    |
-- | Kenny   |
-- | Luca    |
-- | Taylor  |
-- +---------+
--      |
--      |
--     \|/
-- +---------+
-- |  name   |
-- +---------+
-- | Bruce   |
-- | Diana   |
-- | Iman    |
-- | Luca    |
-- +---------+

-- 线索3.
-- As the thief was leaving the bakery, they called someone
-- who talked to them for less than a minute. In the call,
-- I heard the thief say that they were planning to take
-- the earliest flight out of Fiftyville tomorrow. The thief
-- then asked the person on the other end of the phone to
-- purchase the flight ticket.

SELECT name
  FROM people
 WHERE passport_number
    IN (
SELECT passport_number
  FROM passengers
 WHERE flight_id
    IN (
SELECT id
  FROM flights
 WHERE year = 2021
   AND month = 7
   AND day = 29
   AND origin_airport_id
    IN (
SELECT id
  FROM airports
 WHERE city = "Fiftyville")
 ORDER BY hour
 LIMIT 1))
 ORDER BY name;

SELECT name
  FROM people
 WHERE phone_number
    IN (
SELECT caller
  FROM phone_calls
 WHERE year = 2021
   AND month = 7
   AND day = 28
   AND duration < 60)
 ORDER BY name;

-- +--------+
-- |  name  |
-- +--------+
-- | Bruce  |
-- | Doris  |
-- | Edward |
-- | Kelsey |
-- | Kenny  |
-- | Luca   |
-- | Sofia  |
-- | Taylor |
-- +--------+
--      |
--      |
--     \|/
-- +--------+
-- |  name  |
-- +--------+
-- | Bruce  |
-- | Luca   |
-- +--------+
--      |
--      |
--     \|/
-- +--------+
-- |  name  |
-- +--------+
-- | Bruce  |
-- +--------+

-- | 686048 | Bruce | (367) 555-5533 | 5773159633      | 94KL13X       |
-- 当天打给了 (375) 555-8161
-- | 864400 | Robin | (375) 555-8161 |                 | 4V16VO0       |
-- 飞往 New York City