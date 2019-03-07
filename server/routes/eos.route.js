const express = require('express');
const router = express.Router();
const { JsonRpc } = require('eosjs');
const fetch = require('node-fetch');

const rpc = new JsonRpc('http://localhost:8888', { fetch });

/* GET users listing. */
router.get('/', async function(req, res, next) {
  const resp = await rpc.get_table_rows({
      json: true,              // Get the response as json
      code: 'addressbook',     // Contract that we target
      scope: 'addressbook',          // Account that owns the data
      table: 'people',       // Table name
      limit: 10,               // maximum number of rows that we want to get
  });

  console.log(resp);

  //res.send('respond with a resource');

  res.json(resp);
});

module.exports = router;
