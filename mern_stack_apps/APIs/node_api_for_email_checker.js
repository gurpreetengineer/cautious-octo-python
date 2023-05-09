const express = require('express');
const dns = require('dns');
const app = express();

app.get('/check-email', (req, res) => {
  const email = req.query.email;

  if (!email) {
    return res.status(400).json({ message: 'Email address is required' });
  }

  const domain = email.split('@')[1];

  dns.resolveMx(domain, (err, addresses) => {
    if (err || !addresses || addresses.length === 0) {
      return res.status(200).json({ message: 'Email address is not deliverable' });
    }

    return res.status(200).json({ message: 'Email address is deliverable' });
  });
});

app.listen(3000, () => console.log('API listening on port 3000'));
