# -*- coding: utf-8 -*-
import datetime as dt
import flask

from app import app, db, models


@app.route('/', methods=['GET'])
@app.route('/index', methods=['GET'])
def index():
    return flask.jsonify({"answer": "Hello World"})


@app.route('/add_user', methods=['POST'])
def add_user():
    if not flask.request.json:
        flask.abort(400)

    nickname = flask.request.json.get("nickname", None)
    try:
        is_admin = bool(flask.request.json.get("is_admin", "False"))
    except Exception:
        flask.abort(400)

    if not nickname:
        flask.abort(400)

    if not add_user_impl(nickname, is_admin):
        return flask.abort(403)
    return flask.jsonify("OK")


def add_user_impl(nickname, is_admin=False):
    user = models.User.query.filter_by(nickname=nickname).first()
    if user is None:
        user = models.User(nickname=nickname, is_admin=is_admin)
        db.session.add(user)
        db.session.commit()
        return True
    return False


@app.route('/add_post', methods=['POST'])
def add_post():
    if not flask.request.json:
        flask.abort(400)

    nickname = flask.request.json.get("nickname", None)
    text = flask.request.json.get("text", None)

    if not nickname or not text:
        flask.abort(400)

    user = models.User.query.filter_by(nickname=nickname).first()
    if not user:
        return flask.abort(400)

    current_datetime = dt.datetime.now()
    post_db = models.Post(timestamp=current_datetime, body=text, user_id=user.identifier)
    db.session.add(post_db)
    db.session.commit()
    return flask.jsonify("OK")


@app.route('/get_user_posts', methods=['GET'])
def get_user_posts():
    nickname = flask.request.args.get("nickname", None)
    if not nickname:
        flask.abort(400)

    user_db = models.User.query.filter_by(nickname=nickname).first()
    if user_db is None:
        flask.abort(400)

    result = [post_db.body for post_db in user_db.posts.all()]
    return flask.jsonify(result)
