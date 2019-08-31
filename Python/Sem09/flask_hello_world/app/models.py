from app import db


class User(db.Model):
    identifier = db.Column(db.Integer, primary_key=True)
    nickname = db.Column(db.String(64), unique=True)
    is_admin = db.Column(db.Boolean(), default=False)
    posts = db.relationship('Post', backref='author', lazy='dynamic')

    def __repr__(self):
        return '<User %r>' % self.nickname


class Post(db.Model):
    identifier = db.Column(db.Integer, primary_key = True)
    body = db.Column(db.String(140))
    timestamp = db.Column(db.DateTime)
    user_id = db.Column(db.Integer, db.ForeignKey('user.identifier'))

    def __repr__(self):
        return '<Post %r>' % self.body
