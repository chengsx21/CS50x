# Lecture 8

## Routers

- To route data from one place to another, we need to make *==routing decisions==*. You can imagine how data could take multiple paths from point A and point B, such that when a router is ==congested==, data can ==flow through another path==.
- *==TCP/IP==* are two protocols that allow computers to transfer data between them over the internet. *==IP==* or *internet protocol* is a way by which computers can ==identify one another== across the internet. Every computer has a unique address in the world. IP addresses are ==32-bits==, meaning that these addresses could accommodate over 4 billion addresses.
- *==TCP==*, or transmission control protocol, is used to ==distinguish web services== from one another. For example, `80` is used to denote HTTP and `443` is used to denote HTTPS. These numbers are *==port numbers==*.
- When information is sent from one location to another, ==an IP address and TCP port number are sent==.

## DNS

- It would be very tedious if you needed to remember an address number to visit a website. *==DNS==*, or *domain name systems*, is a ==collection of servers== on the internet that are used to route ==website addresses== like *harvard.edu* to a ==specific IP address==.

## HTTP

- *==HTTP==* or *hypertext transfer protocol* is an ==application-level protocol== that developers use to build powerful and useful things.

- When you see an address such as `https://www.example.com` you are actually ==implicitly== visiting that address ==with a `/` at the end== of it. For example, `https://www.example.com/folder/file.html` visits `example.com` and browses to the `folder` folder and then visits the file named `file.html`.

- Type the following in your ==terminal window==:

    ```
      curl -I https://www.harvard.edu
    ```

    Notice that the output of this command returns all the header values of the responses of the server.

- Similarly, execute the following in your terminal window:

    ```
      curl -I http://www.harvard.edu
    ```

    The server response will show that the response is `301` instead of `100`, meaning that the website has permanently moved.

- There are numerous other ==response codes==, such as:

    ```
      200 OK
      301 Moved Permanently
      302 Found
      304 Not Modified
      304 Temporary Redirect
      401 Unauthorized
      403 Forbidden
      404 Not Found
      418 I'm a Teapot
      500 Internal Server Error
      503 Service Unavailable
    ```

- It’s worth mentioning that ==`500` errors are always your fault as the developer==. This will be especially important for next week’s pset, and potentially for your final project!

## HTML

- *==HTML==* or *hypertext markup language* is made up of *tags*, each of which may have ==some *attributes* that describe it==. In your terminal, type `code hello.html` and write code as follows:

    ```html
    <!DOCTYPE html>
    <!-- Demonstrates HTML -->
    <html lang="en">
        <head>
            <title>hello, title</title>
        </head>
        <body>
            hello, body
        </body>
    </html>
    ```

    Notice that the `html` tag both opens and closes this file. Further, notice the `lang` attribute, which modifies the behavior of the `html` tag. Also, notice that there are both `head` tags and `body` tags. ==Indentation== is not required but does ==suggest a hierarchy==.

- The hierarchy of tags can be represented as follows:

    ![html code next to a heirarchy showing parent and child nodes](https://cs50.harvard.edu/x/2023/notes/8/cs50Week8Slide065.png)

- Because whitespace is effectively ignored in HTML, you will need to use ==`<p>` paragraph tags== to open and close a paragraph.

- We can also ==create lists== within HTML:

    ```html
    <!DOCTYPE html>
    <!-- Demonstrates (ordered) lists -->
    <html lang="en">
        <head>
            <title>list</title>
        </head>
        <body>
            <ol>
                <li>foo</li>
                <li>bar</li>
                <li>baz</li>
            </ol>
        </body>
    </html>
    ```

    Notice that the `<ol>` tag ==creates an ordered list containing three items==.

- We can also ==create a table== in HTML:

    ```html
    <!DOCTYPE html>
    <!-- Demonstrates table -->
    <html lang="en">
        <head>
            <title>table</title>
        </head>
        <body>
            <table>
                <tr>
                    <td>1</td>
                    <td>2</td>
                    <td>3</td>
                </tr>
                <tr>
                    <td>4</td>
                    <td>5</td>
                    <td>6</td>
                </tr>
                <tr>
                    <td>7</td>
                    <td>8</td>
                    <td>9</td>
                </tr>
                <tr>
                    <td>*</td>
                    <td>0</td>
                    <td>#</td>
                </tr>
            </table>
        </body>
    </html>
    ```

    Tables also have tags that open and close each element within.

- ==Images== can also be utilized within HTML:

    ```
    <!DOCTYPE html>
    
    <!-- Demonstrates image -->
    
    <html lang="en">
        <head>
            <title>image</title>
        </head>
        <body>
            <!-- https://www.harvard.edu/ -->
            <img alt="Harvard University" src="harvard.jpg">
        </body>
    </html>
    ```

    Notice that `src="harvard.jpg"` indicates the path where the image file can be located.

- You can also ==link== between various web pages:

    ```HTML
    <!DOCTYPE html>
    <!-- Demonstrates link -->
    <html lang="en">
        <head>
            <title>link</title>
        </head>
        <body>
           Visit <a href="image.html">Harvard</a>.
        </body>
    </html>
    ```

- ==Meta tags== are used to hold information about the data within the HTML file. Consider the following:

    ```html
    <!DOCTYPE html>
    <!-- Demonstrates responsive design -->
    <html lang="en">
        <head>
            <meta name="viewport" content="initial-scale=1, width=device-width">
            <title>meta</title>
        </head>
        <body>
            Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vivamus convallis scelerisque quam, vel hendrerit lectus viverra eu.
        </body>
    </html>
    ```

    Notice this set of `meta` attributes makes this page ==mobile-friendly==.

- You can also create ==forms== reminiscent of Google’s search:

    ```html
    <!DOCTYPE html>
    <!-- Demonstrates form -->
    <html lang="en">
        <head>
            <title>search</title>
        </head>
        <body>
            <form action="https://www.google.com/search" method="get">
                <input name="q" type="search">
                <input type="submit" value="Google Search">
            </form>
        </body>
    </html>
    ```

    Notice that a `form` tag opens and provides the attribute of what `action` it will take. The `input` field is included, passing the name `q` and the type as `search`. We can make this search better by ensuring that `autocomplete` is turned `off`. `autofocus` is enabled.

## CSS

- `CSS`, or *==cascading style sheet==*, is a markup language that allows you to fine-tune the aesthetics of your HTML files.

    ```html
    <!DOCTYPE html>
    <!-- Demonstrates inline CSS with P tags -->
    <html lang="en">
        <head>
            <title>css</title>
        </head>
        <body>
            <p style="font-size: large; text-align: center;">
                John Harvard
            </p>
            <p style="font-size: medium; text-align: center;">
                Welcome to my home page!
            </p>
            <p style="font-size: small; text-align: center;">
                Copyright &#169; John Harvard
            </p>
        </body>
    </html>
    ```

    Notice that some ==`style` attributes== are provided to the `<p>` tags. The `font-size` is set to `large`, `medium`, or `small`. Then `text-align` is set to center.

- We can remove redundancy by modifying our code as follows:

    ```html
    <!DOCTYPE html>
    <!-- Uses semantic tags instead of DIVs -->
    <html lang="en">
        <head>
            <title>css</title>
        </head>
        <body style="text-align: center">
            <header style="font-size: large">
                John Harvard
            </header>
            <main style="font-size: medium">
                Welcome to my home page!
            </main>
            <footer style="font-size: small">
                Copyright &#169; John Harvard
            </footer>
        </body>
    </html>
    ```

- This practice of ==placing the style and information all in the same location== is ==not good practice==. We could move the elements of style to the top of the file as follows:

    ```html
    <!-- Demonstrates class selectors -->
    <html lang="en">
        <head>
            <style>
                .centered {
                    text-align: center;
                }
                .large {
                    font-size: large;
                }
                .medium {
                    font-size: medium;
                }
                .small {
                    font-size: small;
                }
            </style>
            <title>css</title>
        </head>
        <body class="centered">
            <header class="large">
                John Harvard
            </header>
            <main class="medium">
                Welcome to my home page!
            </main>
            <footer class="small">
                Copyright &#169; John Harvard
            </footer>
        </body>
    </html>
    ```

    Notice all the style tags are placed up in the `head` in the `style` tag wrapper. Also notice that we’ve ==assigned *classes*==, called `centered`, `large`, `medium`, and `small` ==to our elements,== and that we select those classes by placing a dot before the name, as in `.centered`

- It turns out that we can ==move all our style code== into a special file called ==a *CSS* file==. We then can tell the browser where to locate the CSS for this HTML file:

    ```html
    <!DOCTYPE html>
    <!-- Demonstrates external stylesheets -->
    <html lang="en">
        <head>
            <link href="style.css" rel="stylesheet">
            <title>css</title>
        </head>
        <body class="centered">
            <header class="large">
                John Harvard
            </header>
            <main class="medium">
                Welcome to my home page!
            </main>
            <footer class="small">
                Copyright &#169; John Harvard
            </footer>
        </body>
    </html>
    ```

    Notice that `style.css` is ==linked to this HTML file as a stylesheet==, telling the browser where to locate the styles we created.

## Frameworks

- Similar to third-party libraries we can leverage in Python, there are ==third-party libraries called *frameworks*== that we can utilize with our ==HTML files==.

- *==Bootstrap==* is one of these frameworks that we can use to beautify our HTML and easily perfect design elements such that our pages are more readable. Bootstrap can be utilized by ==adding the following `link` tag== in the `head` of your html file:

    ```
    <head>
        <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.2.2/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-Zenh87qX5JnK2Jl0vWa8Ck2rdkQ2Bzep5IDxbcnCeuOxjzrPF/et3URy9Bv1WTRi" crossorigin="anonymous">
        <title>favorites</title>
    </head>
    ```

## JavaScript

- JavaScript is another programming language that ==allows for interactivity within web pages==.

- JavaScript allows you to ==dynamically read and modify== the html document loaded into memory such that the user ==need not reload to see changes==.

    ```html
    <!DOCTYPE html>
    <!-- Demonstrates programmatic changes to style -->
    <html lang="en">
        <head>
            <title>background</title>
        </head>
        <body>
            <button id="red">R</button>
            <button id="green">G</button>
            <button id="blue">B</button>
            <script>
                let body = document.querySelector('body');
                document.querySelector('#red').addEventListener('click', function() {
                    body.style.backgroundColor = 'red';
                });
           document.querySelector('#green').addEventListener('click', function() {
                    body.style.backgroundColor = 'green';
                });
                document.querySelector('#blue').addEventListener('click', function() {
                    body.style.backgroundColor = 'blue';
                });
            </script>
        </body>
    </html>
    ```

    Notice that JavaScript listens for when a specific button is clicked. Then, the `body.style.backgroundColor` is changed.

- Similarly, consider the following:

    ```html
    <!DOCTYPE html>
    <html lang="en">
        <head>
            <script>
                // Toggles visibility of greeting
                function blink() {
                    let body = document.querySelector('body');
                    if (body.style.visibility == 'hidden') {
                        body.style.visibility = 'visible';
                    }
                    else {
                        body.style.visibility = 'hidden';
                    }
                }
                // Blink every 500ms
                window.setInterval(blink, 500);
            </script>
            <title>blink</title>
        </head>
        <body>
            hello, world
        </body>
    </html>
    ```

    This example blinks a text at a set interval. Notice that `window.setInterval` takes in two arguments: 1) A function to be called and 2) a wait period (in milliseconds) between function calls.