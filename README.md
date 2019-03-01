# eos-express-react-starter


## 1 |  Description

A starter app for EOS using Node.js, Express, React, and React-Native.

## 2 |  Roadmap

### 2.1 Minimal Viable Product (MVP)



## 3 | Getting Started


### 3.1 Installing

1. Clone project

```
git clone https://github.com/johnworthley/icotracker.git
```

2. Install dependencies in both `cd ./frontend` and `cd ./backend`

```
npm install || yarn
```


### 3.2 Running

You can run as a web, phone, or desktop app.


#### Running the Backend

You must run the backend first. The backend requires MongoD to be running first.

In `./backend`:

Begin MongoD.

```
mongod
```

Then run the server

```
npm run dev || yarn dev || npm run start || yarn start
```

Running the script `dev` will use `nodemon` which restarts the server upon
changes in code.

The back-end will be running in localhost:4000.

#### Running the Frontend

The front-end will run in localhost:3000.

In `./frontend`:

For Mobile:

```
npm run start || yarn start || exp start
```

For Web:

```
npm run web || yarn web
```

For Desktop:

```
npm run desktop || yarn desktop
```

## 4.0 Building

Make sure you have installed the latest expo CLI. Inside `frontend`, to build on mobile, run:

```
expo build:ios || expo build:android
```

To build for ios or android.  

For building in android, if the following error occurs:

```
connect ECONNREFUSED 127.0.0.1:19001
```

Try the following:

- `expo start`
- Cancel `ctrl c`
- then do `expo build:android`
